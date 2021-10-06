import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;

public class Test {
    private static void check() {
        // enter your file name to check its existence
        File f = new File("./inno_java.iml");
        if (!f.isFile() && !f.isDirectory()) {
            System.out.println("The file does not exist");
        } else {
            System.out.println("The file exists");
        }
    }

    private static void dir_or_file() {
        // enter your file name to check its existence
        File f = new File("./out");
        if (!f.isFile() && !f.isDirectory()) {
            System.out.println("The file does not exist");
        } else if (f.isFile()){
            System.out.println("It's a file");
        } else if (f.isDirectory()) {
            System.out.println("It's a directory");
        }
    }

    private static void read_write() {
        File f = new File("input.txt");
        Path f_output = Paths.get("output.txt");
        try {
            ArrayList<String> s = new ArrayList<String>();
            Scanner in = new Scanner(f);
            while (in.hasNextLine()) {
                s.add(in.nextLine());
            }
            Files.write(f_output, s, StandardCharsets.UTF_8);
        } catch (FileNotFoundException e) {
            System.out.println("File not found!");
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
//        check();
//        dir_or_file();
        read_write();
    }
}
