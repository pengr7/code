var sorce = 0, time = 30, ran = -1, started = 0, itime, i;
window.onload = function () {
	for (i = 0; i < 60; i++) {
		var obj = document.getElementById("panel"), e = document.createElement("input");
		e.type = "radio";
		e.name = "moles";
		e.onclick = s;
		var ob = obj.appendChild(e);
	}
	document.getElementById("start").onclick = function () {
		if (started) {
			time = 0;
		} else {
			document.getElementById("state").value = "Playing";
			document.getElementById("time").value = time;
			sorce = 0;
			document.getElementById("sorce").value = sorce;
			ran = parseInt(Math.random() * 59);
			document.getElementsByName("moles")[ran].checked = true;
			time = 30;
			itime = self.setTimeout("timer()", 1000);
			started = 1;
		}	
	}
}
function s() {
	if (started) {
		if (document.getElementsByName("moles")[ran].checked){
			sorce++;
			document.getElementById("sorce").value = sorce;
			this.checked = false;
			ran = parseInt(Math.random() * 59);
			document.getElementsByName("moles")[ran].checked = true;
		} else {
			this.checked = false;
			document.getElementsByName("moles")[ran].checked = true;
			sorce--;
			document.getElementById("sorce").value = sorce;
		}
	}
}
function timer() {
	if (time) {
		time--;
		document.getElementById("time").value = time;
		itime = self.setTimeout("timer()", 1000);
	} else {
		gameover();
	}

}
function gameover() {
	started = 0;
	alert("Game Over.\nYou score is: " + sorce);
	document.getElementById("state").value = "Game Over";
	window.clearTimeout(int);
}
