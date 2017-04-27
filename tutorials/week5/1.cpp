int mod(int dividend, int divisor){
	if (divisor==0) throw string("Divisor cannot be zero");
	if (divisor<0) throw string("Divisor cannot be negative");

	while (dividend<0)
		dividend+=divisor;

	return dividend % divisor;
}