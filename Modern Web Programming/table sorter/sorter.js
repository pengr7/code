var temp = {array: [0, 0, 0, 0, 0, 0]};
$(document).ready(click);
function click() {
    $("th").each(function(i) {$(this).click(function() {start(i);});});
}
function start(i) {
	arr = new Array();
	$("thead:eq(" + Math.floor(i / 3) + ") th").each(function() {$(this).attr('class', '');});
	temp.array[i] ? $("th:eq(" + i + ")").addClass("descend") : $("th:eq("+ i + ")").addClass("ascend");
	$("tbody:eq(" + Math.floor(i / 3) + ") tr").each(function() {t = new Array(); $(this).find("td").each(function() {t.push($(this).html());}); arr.push(t);});
	arr.sort(function(x, y) {return temp.array[i] ? x[i%3] < y[i%3] : x[i%3] > y[i%3];});
	$("tbody:eq(" + Math.floor(i / 3) + ") tr").each(function(j) {$(this).find("td").each(function(k) {$(this).html(arr[j][k]);})});
	temp.array[i] = 1 - temp.array[i];
}
