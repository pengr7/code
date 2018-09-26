var started, cheat;
function showmessage (message) {
	document.getElementById("message").textContent = message;
}
window.onload = function () {
	document.getElementById("s").onmouseover = function() {
		showmessage("");
		started = 1;
		cheat = 0;
	}
	document.getElementById("w2").onmouseover = function() {
		if (started == 1) {
			showmessage ("You Lose");
			started = 0;
			document.getElementById("w2").style.backgroundColor = '#FF0000';
		}
	}
	document.getElementById("w2").onmouseout = function() {
		document.getElementById("w2").style.backgroundColor = '#F0F0F0';
	}
	document.getElementById("w4").onmouseover = function() {
		if (started == 1) {
			showmessage ("You Lose");
			started = 0;
			document.getElementById("w4").style.backgroundColor = '#FF0000';
		}
	}
	document.getElementById("w4").onmouseout = function() {
		document.getElementById("w4").style.backgroundColor = '#F0F0F0';
	}
	document.getElementById("w5").onmouseover = function() {
		if (started == 1) {
			showmessage ("You Lose");
			started = 0;
			document.getElementById("w5").style.backgroundColor = '#FF0000';
		}
	}
	document.getElementById("w5").onmouseout = function() {
		document.getElementById("w5").style.backgroundColor = '#F0F0F0';
	}
	document.getElementById("w6").onmouseover = function() {
		if (started == 1) {
			showmessage ("You Lose");
			started = 0;
			document.getElementById("w6").style.backgroundColor = '#FF0000';
		}
	}
	document.getElementById("w6").onmouseout = function() {
		document.getElementById("w6").style.backgroundColor = '#F0F0F0';
	}
	document.getElementById("w7").onmouseover = function() {
		if (started == 1) {
			showmessage ("You Lose");
			started = 0;
			document.getElementById("w7").style.backgroundColor = '#FF0000';
		}
	}
	document.getElementById("w7").onmouseout = function() {
		document.getElementById("w7").style.backgroundColor = '#F0F0F0';
	}
	document.getElementById("w8").onmouseover = function() {
		if (started == 1) {
			showmessage ("You Lose");
			started = 0;
			document.getElementById("w8").style.backgroundColor = '#FF0000';
		}
	}
	document.getElementById("w8").onmouseout = function() {
		document.getElementById("w8").style.backgroundColor = '#F0F0F0';
	}
	document.getElementById("c").onmouseover = function() {
		cheat = 1;
	}
	document.getElementById("e").onmouseover = function() {
		if (started == 1 && cheat == 0)
			showmessage ("You Win");
		if (started == 1 && cheat == 1)
			showmessage ("Don't cheat, you should start form the 'S' and move to the 'E' inside the maze!");
	}
	document.getElementById("e").onmouseout = function() {
		cheat = 0;
		started = 0;
	}
}
