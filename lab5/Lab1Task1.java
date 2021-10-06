import java.util.Scanner;

public class Lab1Task1 {
    public static void swap() {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt(), b = in.nextInt();
        int c = a;
        a = b;
        b = c;
        System.out.println(a + " " + b);
    }

    public static void get_ascii() {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        char c = str.charAt(0);
        System.out.println((int) c);
    }

    public static void get_index() {
        int a = (int) 'a';
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        char c = str.charAt(0);
        System.out.println((int) c - a);
    }

    public static void compare_strings() {
        Scanner in = new Scanner(System.in);
        String string1 = in.nextLine();
        String string2 = in.nextLine();
        boolean is_len_eq = string1.length() == string2.length();
        if (is_len_eq) {
            boolean flag = false;
            for (short i = 0; i < string1.length(); i++) {
                if (string1.charAt(i) != string2.charAt(i)) {
                    flag = true;
                    break;
                }
            }
            System.out.println(flag ? "Not equal" : "Equal");
        } else {
            System.out.println("Not equal");
        }
    }

    public static void count_vowels() {
        Scanner in = new Scanner(System.in);
        String in_str = in.nextLine();
        char[] vowels = {'a', 'o', 'e', 'i', 'u', 'y'};
        short res = 0;
        for (short i = 0; i < in_str.length(); i++) {
            for (short j = 0; j < vowels.length; j++) {
                if (in_str.charAt(i) == vowels[j]) {
                    res++;
                    break;
                }
            }
        }
        System.out.println(res);
    }

    public static void main(String[] args) {
//        swap();
//        get_ascii();
//        get_index();
//        compare_strings();
        count_vowels();
    }
}
