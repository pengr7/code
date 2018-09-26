var flag = false;
function getNum(num) {
    var o = document.getElementById("result");
    if (flag) {
        o.value = "";
        flag = false;
    }
    o.value += num;
}
function Clear(){
    var o = document.getElementById("result");
    o.value = "";
}
function Return(){
    var str1 = String(document.getElementById("result").value), str2 = str1.substring(0, str1.length-1);
    document.getElementById("result").value = str2;
}
function getResult(){
  	if (document.getElementById("result").value.length > 0) {
    	try {
      		document.getElementById("result").value = eval(document.getElementById("result").value);
    	}
    	catch(err) {
      		document.getElementById("result").value = "ERROR";
    	}
    	flag = true;
  	}
}
