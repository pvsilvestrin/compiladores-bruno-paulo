declare a: integer [10];
//declare b: floating [10];
//declare c: floating;
declare d: integer;

main: integer() {
	d = fun(5, 6);

	output d;

/*


	b[4] = 666;
	b[5] = 777.777;
	b[6] = 'a';
	b[7] = true;

	c = 2.0;
	c = 2;
	//c = 8< 4;
	//b = 20.0/'a';
	output a[2], a[3], a[4], b[4], 'a', b[5], 'a', b[6], 'a', b[7], c;//1 != 2.0, 'a' == 97.0, 1000 <= 9000, 1000 >= 9000;*/
};

fun: integer(numero: integer, numero2: integer) {
	return numero + 1;
};