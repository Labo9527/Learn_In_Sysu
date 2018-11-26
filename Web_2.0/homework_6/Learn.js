window.onload=function () {
  $("<div></div>").appendTo("#div1");
  $("#div1").click(function () {
    $("#div1:first").animate({"width":"300px"},500);
    $("#div1:first").animate({"height":"300px"},500);
  })
}
