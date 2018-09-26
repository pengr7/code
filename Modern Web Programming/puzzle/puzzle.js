var p = {}, q = {};
window.onload = function () {
	for (i = 1; i < 16; i++)
		q[i] = document.getElementById('ph' + i);
	document.getElementById("start").onclick = function () {
		for (i = 1; i < 16; i++)
			q[i].id = "ph" + i;
		for (i = 0; i < 16; i++)
			p[i] = 0;
		p[16] = 1;
		for (i = 0; i < 16; i++) {
			r1 = parseInt(Math.random()*15);
			r2 = parseInt(Math.random()*15);
			t1 = document.getElementsByClassName('photo')[r1];
			t2 = document.getElementsByClassName('photo')[r2];
			t = t1.id;
			t1.id = t2.id;
			t2.id = t;
		}
	}
	c = document.getElementsByClassName('photo');
    for (i = 0; i < c.length; i++)
        c[i].onclick = click;
}
function click() {
	for (i = 1; i <= 16; i++)
		if (this.id == "ph" + i)
			u = i;
	if (p[u+4]) {
		this.id = "ph" + (u+4);
		p[u] = 1;
		p[u+4] = 0;
	}
	if (p[u-4]) {
		this.id = "ph" + (u-4);
		p[u] = 1;
		p[u-4] = 0;
	}
	if (p[u+1] && u%4) {
		this.id = "ph" + (u+1);
		p[u] = 1;
		p[u+1] = 0;
	}
	if (p[u-1] && u%4 != 1) {
		this.id = "ph" + (u-1);
		p[u] = 1;
		p[u-1] = 0;
	}
	for (i = 1, check = 1; i < 16; i++)
		if (q[i].id != "ph" + i)
			check = 0;
	if (check)
		alert("win");
}
