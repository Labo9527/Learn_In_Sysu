window.onload = function () {
  document.getElementById("Input").value="";
}

function Input9(){
  document.getElementById("Input").value+="9";
}

function Input0(){
  document.getElementById("Input").value+="0";
}

function Input1(){
  document.getElementById("Input").value+="1";
}

function Input2(){
  document.getElementById("Input").value+="2";
}

function Input3(){
  document.getElementById("Input").value+="3";
}

function Input4(){
  document.getElementById("Input").value+="4";
}

function Input5(){
  document.getElementById("Input").value+="5";
}

function Input6(){
  document.getElementById("Input").value+="6";
}

function Input7(){
  document.getElementById("Input").value+="7";
}

function Input8(){
  document.getElementById("Input").value+="8";
}

function Inputx() {
  document.getElementById("Input").value+="*";
}

function Inputc() {
  document.getElementById("Input").value+="/";
}

function Inputj() {
  document.getElementById("Input").value+="-";
}

function Inputd() {
  document.getElementById("Input").value+=".";
}

function Inputa() {
  document.getElementById("Input").value+="+";
}

function Inputl() {
  document.getElementById("Input").value+="(";
}

function Inputr() {
  document.getElementById("Input").value+=")";
}

function Del() {
  document.getElementById("Input").value=document.getElementById("Input").value.substr(0,document.getElementById("Input").value.length-1);
}

function Clear() {
  document.getElementById("Input").value="";
}

function Calcute() {
  try {
    document.getElementById("Input").value = eval(document.getElementById("Input").value);
  }
  catch{
    alert("Error!");
  }
}

document.onkeydown = function () {
  if(event.keyCode=='49')
    Input1();
  else if(event.keyCode=='50')
    Input2();
  else if(event.keyCode=='51')
    Input3();
  else if(event.keyCode=='52')
    Input4();
  else if(event.keyCode=='53')
    Input5();
  else if(event.keyCode=='54')
    Input6();
  else if(event.keyCode=='55')
    Input7();
  else if(event.keyCode=='56')
    Input8();
  else if(event.keyCode=='57')
    Input9();
  else if(event.keyCode=='48')
    Input0();
}
