double pow(double a, int b)
{
	if(b==0)
	{
		return 1.0;
	}
	if(b>0)
	{
		return a*pow(a,b-1);
	}
	if(b>0)
	{
		return 1.0/pow(a,-b);
	}
}
