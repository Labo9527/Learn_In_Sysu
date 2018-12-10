var http=require("http");
var fs=require('fs');

var server=http.createServer(function (request,response) {
  //console.log(request.url)
  if(request.url=='/S1/index.html'){
    response.writeHead(200,{'Content-Type':'text/html'});
    response.end(fs.readFileSync('./index.html'));
  }
  else if(request.url=='/S1/style.css'){
    response.writeHead(200,{'Content-Type':'text/css'});
    response.end(fs.readFileSync('./style.css'));
  }
  else if(request.url=='/S1/S1.js'){
    response.writeHead(200,{'Content-Type':'application/x-javascript'});
    response.end(fs.readFileSync('./S1.js'));
  }
  else if(request.url=='/S1/assets/images/favicon.png'){
    response.writeHead(200,{'Content-Type':'image/png'});
    response.end(fs.readFileSync('./assets/images/favicon.png'));
  }
  else if(request.url=='/S1/assets/images/atplus_white.png'){
    response.writeHead(200,{'Content-Type':'image/png'});
    response.end(fs.readFileSync('./assets/images/atplus_white.png'));
  }
  else if(request.url=='/S1/assets/images/atplus_green.png'){
    response.writeHead(200,{'Content-Type':'image/png'});
    response.end(fs.readFileSync('./assets/images/atplus_green.png'));
  }
  else {
    console.log(103)
    setTimeout(function () {
      response.writeHead(200, {'Content-Type': 'text/plain'});
      response.end(""+GetRandomNum());
    }, GetRandomTime()*1000);
  }
}).listen(3000);

console.log("Server is running at 3000");

function GetRandomTime() {
  var Res=Math.floor(Math.random()*10);
  while(Res==9)
    Res=Math.floor(Math.random()*10);
  return Res%3+1;
}

function GetRandomNum() {
  return Math.floor(Math.random()*10+1);
}
