<?php

  function essential_my_view() {
    global $user;
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'teacher_essential');
      $result = $query->execute();
        if (isset($result['node'])) {
          $nids = array_keys($result['node']);
          $nodes = node_load_multiple($nids);
        }
         $ess = array();
         foreach ($nodes as $key => $node) {
      // dpm($node);
            $uid = $node->uid;
            $pid = $user->uid;
              if($uid==$pid) {
                $ess[$key]['title'] = $node->title;
                  if (!empty($node->body)) {
                    $ess[$key]['body'] = substr($node->body['und'][0]['value'],0,500);
                  }
                     $ess[$key]['link'] = 'node/' . $node->nid;


              }
          }
             $per_page = 3;
             $current_page = pager_default_initialize(count($ess),($per_page));
             $chunks = array_chunk($ess,$per_page,TRUE);
             $output = theme('Teaser', array('variables' => $chunks[$current_page]));
             $output .= theme('pager', array('quantity',count($ess)));
             return $output;
  }

