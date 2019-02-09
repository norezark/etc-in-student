class QuadEquation {
    enum SolutionType {REAL, DOUBLE, COMPLEX, LINEAR, NONE, INDEF};
    SolutionType getSolution(double a, double b, double c) {
	double d, x;
	SolutionType soltype = SolutionType.REAL;

	if (a != 0) {
	    b = b/a;
	    c = c/a;
	    if (c != 0) {
		b = b / 2;
		d = b * b - c;
		if (d > 0) {
		    if (b > 0)
			x = -b - Math.sqrt(d);
		    else
			x = -b + Math.sqrt(d);
		    System.out.println("x = " + x + ", " + c/x);
		} else if (d < 0) {
		    System.out.println("x = " + (-b) + "+-" + Math.sqrt(-d) + "i");
		    soltype = SolutionType.COMPLEX;
		} else {
		    System.out.println("x = " + (-b));
		    soltype = SolutionType.DOUBLE;
		}
	    } else {
		System.out.println("x = " + (-b) + ", 0");
	    }
	} else if (b != 0) {
	    System.out.println("x = "+ (-c / b));
	    soltype =  SolutionType.LINEAR;
	} else if (c != 0) {
	    System.out.println("解なし");
	    soltype =  SolutionType.NONE;
	} else {
	    System.out.println("不定");
	    soltype = SolutionType.INDEF;
	}
	return soltype;
    }
}
