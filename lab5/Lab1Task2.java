import java.util.Scanner;

public class Lab1Task2 {
    private static void f_to_c() {
        Scanner in = new Scanner(System.in);
        double temp_f = in.nextDouble();
        double temp_c = (temp_f - 32) * 5/9;
        System.out.println(temp_c);
    }

    private static void convert() {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        System.out.println("bin: " + Integer.toString(num, 2));
        System.out.println("dec: " + num);
        System.out.println("hex: " + Integer.toString(num, 16));
    }
    public static void main(String[] args) {
//        f_to_c();
        convert();
    }
}
