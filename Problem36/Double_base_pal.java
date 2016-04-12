import java.math.BigInteger;

public class Double_base_pal {

    public static void main(String args[]) {

        int limit = 1000000, sum = 0;

        for(int j = 1; j<limit; j+=2){
            BigInteger k = BigInteger.valueOf(j);
	    BigInteger binar = binary(j);
	    if(CheckPalindrome(k) == true)
		if(CheckPalindrome( binar ) == true)
		    sum+=j;
	}
	System.out.println("sum = " + sum);
    }

    public static boolean CheckPalindrome(BigInteger i){
        BigInteger j = BigInteger.valueOf(0), remainder;
        BigInteger hold = i;
        // compare bi1 with bi2
        while( i.equals(BigInteger.valueOf(0) ) == false ){
            // perform remainder operation on i using 10
            remainder = i.remainder(BigInteger.valueOf(10));
            // multiply j with 10 and assign result to j
            j = j.multiply(BigInteger.valueOf(10));
            // perform add operation on j using remainder
            j = j.add(remainder);
            // divide i with 10
            i = i.divide(BigInteger.valueOf(10));
        }
        if (j.equals(hold) == true) return true;
        else return false;
    }

    public static BigInteger binary(int i){
        BigInteger bina = BigInteger.valueOf(0);
        BigInteger bina2 = BigInteger.valueOf(0);
        BigInteger ten = BigInteger.valueOf(10);
        BigInteger two = BigInteger.valueOf(2);

        int n;

        double M = 0.30102999566;
        while(i > 0){
	    // 4, 2
            n = (int) (Math.log10(i)/M);
	    //System.out.println("n = " + n);
            bina = ten.pow(n);  // 10000, 10100
	    //System.out.println("bina = " + bina);
            bina2 = bina2.add(bina);
	    //System.out.println("bina2 = " + bina2);
            i = (int)(i - Math.pow(2, n)); // 7, 2
        }
        //System.out.println("binary = " + bina2);
        return bina2;
    }
}
