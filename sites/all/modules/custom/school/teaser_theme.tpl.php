<?php
// dpm($variables);
?>


<div class="new-artical-page">
  <?php foreach ($variables['variables'] as $key => $value): ?>
    <div class="article article-<?php print $key ?>">
    <div class="title"><h1><?php print $value['title']; ?></h1></div>
    <?php if(isset($value['body'])): ?>
    <div class="body"><p><?php print $value['body']; ?></p></div>
    <?php endif ?>
    <div class="link"><a href="/<?php print $value['link']; ?>">Read More</a></div>
    </div>
    <div class = "line" >
    <hr style = "color: black;">
    </div>
  <?php endforeach; ?>
</div>



