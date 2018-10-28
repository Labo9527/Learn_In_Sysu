window.onload=function () {
  Cheat=true;
  Lose_Time=0;
  Began=false;
  setInterval(function () {
    if(Began){
      document.getElementById("Post").innerText="Game Began!";
    }
    else{
      document.getElementById("Post").innerText="Move your mouse over the \"S\" to begin.";
    }
  },100)
  var List=document.getElementsByClassName("wall");
  for(var i=0;i<11;i++) {
    List[i].onmouseenter = Crash;
    List[i].onmouseout=Leave;
  }
  setInterval(function () {
    Lose_Time++;
  },1000);
  setInterval(function () {
    if(!Began){
      document.getElementById("Cheat_Inform").innerText="If you are winner will be showed here.";
    }
  },100)
  document.getElementById("Out").onmouseover=Reach;
  document.getElementById("Anti_Cheat").onmouseover=Anti;
  document.getElementById("Enter").onmouseover=function () {
    Cheat=true;
    Began=true;
  }
}

function Anti() {
  Cheat=false;
}

function Reach(){
  if(!Began)
    return;
  if(Cheat)
    document.getElementById("Cheat_Inform").innerText="Don't cheat, you should start form the 'S' and move to the 'E' inside the maze!";
  else
    document.getElementById("Cheat_Inform").innerText="You Win!";
  Cheat=true;
  setTimeout("Began=false;",1000);
}

function Crash() {
  if(!Began)
    return;
  var List=document.getElementsByClassName("wall");
  for(var i=0;i<11;i++) {
    List[i].style.backgroundColor = "red";
  }
  if(Lose_Time>=0&&Began) {
    setTimeout("document.getElementById(\"Cheat_Inform\").innerText=\'You Lose!\';", 1);
    setTimeout("Began=false;",1000);
    Lose_Time=0;
  }
}

function Leave(){
  var List=document.getElementsByClassName("wall");
  for(var i=0;i<11;i++) {
    List[i].style.backgroundColor = "lightgrey";
  }
}
