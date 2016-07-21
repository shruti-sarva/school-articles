<?php
  function myblock_view($type) {
  // dpm($type);
    if($type == 'news' || $type == 'base') {
      $bundle = 'news_article';
    }
      if($type == 'essential') {
        $bundle = 'teacher_essential';
      }
        $query1 = new EntityFieldQuery();
        $query1->entityCondition('entity_type', 'node')
       ->entityCondition('bundle', $bundle)
       ->propertyOrderBy('nid' , 'DESC')
       ->propertyCondition('status', 1)
       ->range(0,5);
        $result = $query1->execute();
   // dpm($result);
          if (isset($result['node'])) {
            $nids1 = array_keys($result['node']);
            $nodes1 = node_load_multiple($nids1);
          }
          $list = array();
  //dpm($nodes);
          foreach ($nodes1 as $key => $value) {
  // $list = array();
            $list[] = l($value->title ,'node/'.$value->nid);
          }
            $theme_args = array('items' => $list, 'type' => 'ul');
            $content = theme('item_list', $theme_args);

            return $content;
 }
