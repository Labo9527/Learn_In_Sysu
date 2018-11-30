window.onload=function(){
  console.log('there');
  $('input:not(.button)').blur(function () {
    console.log("here");
    if(check.isRight(this.id,$(this).val())){
      $(this).next().hide();
    }
    else{
      /*
      console.log(check.exam);
      console.log("wrong");
      console.log($(this));
      console.log($(this).next());
      */
      $(this).next().text(check.exam[this.id].Message).show();
    };
  });
  $('.submit').click(function () {
    $('input:not(.button)').blur();
    if(check.allRight()==false){
      return false;
    }
  });
  $('.reset').click(function () {
    $('input:not(.button)').text("");
  });
};
