<?php

  function news_my_view() {
    global $user;
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'news_article');
      $result = $query->execute();
        if (isset($result['node'])) {
          $nids = array_keys($result['node']);
          $nodes = node_load_multiple($nids);
        }
          $articles = array();
          foreach ($nodes as $key => $node) {
      // dpm($node);
           $uid = $node->uid;
           $pid = $user->uid;
            if($uid==$pid) {
              $articles[$key]['title'] = $node->title;
                if (!empty($node->body)) {
                  $articles[$key]['body'] = substr($node->body['und'][0]['value'],0,500);
                }
                    $articles[$key]['link'] = 'node/' . $node->nid;
            }
          }
             $per_page = 3;
             $current_page = pager_default_initialize(count($articles),($per_page));
             $chunks = array_chunk($articles,$per_page,TRUE);
             $output = theme('Teaser', array('variables' => $chunks[$current_page]));
             $output .= theme('pager', array('quantity',count($articles)));
             return $output;
  }
    //                 return theme('Teaser', array('variables' => $articles));
    // }
