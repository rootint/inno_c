import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Lab1Task3 {
    private static void average() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayList<Integer> lst = new ArrayList<Integer>();
        int sum = 0;
        for (short i = 0; i < n; i++) {
            int tmp = in.nextInt();
            lst.add(tmp);
            sum += tmp;
        }
        System.out.println(sum / lst.size());
    }

    private static void insert() {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter n:");
        int n = in.nextInt();
        int[] arr = new int[1000];
        System.out.println("Enter each element one by one:");
        for (short i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        System.out.println("Enter insert value and insert position:");
        int insert_val = in.nextInt();
        int insert_pos = in.nextInt();
        n++;
        for (int i = n - 1; i >= insert_pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[insert_pos] = insert_val;
        for (short i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    private static void duplicates() {
        System.out.println("The array will be generated randomly. Please stand by...");
        int n = 10;
        int[] arr = new int[n];
        for (short i = 0; i < n; i++) {
            arr[i] = (int) ((Math.random() * (10 - 1)) + 1);
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        Map<Integer, Integer> dict = new HashMap<Integer, Integer>();
        for (short i = 0; i < n; i++) {
            if (dict.containsKey(arr[i])) {
//                System.out.println(arr[i] + " is repeated!");
//                dict.put(arr[i], 2);
                dict.put(arr[i], dict.get(arr[i]) + 1);
            } else {
                dict.put(arr[i], 1);
            }
        }
        for (Map.Entry<Integer, Integer> i : dict.entrySet()) {
            if (i.getValue() != 1) {
                System.out.println(i.getKey() + " appeared " + i.getValue() + " times.");
            }
        }
    }

    public static void main(String[] args) {
//        average();
//        insert();
        duplicates();
    }
}
