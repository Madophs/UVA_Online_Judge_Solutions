import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer tk =  new StringTokenizer("");

    public static int countSequence(int value) {
        int counter = 1;
        while (value != 1) {
            ++counter;
            if (value % 2 != 0) {
                value = 3 * value + 1;
            } else {
                value /= 2;
            }
        }
        return counter;
    }

    public static int maxSequence(int i, int j) {
        int maxValue = 1;
        for (; i <= j; ++i) {
            maxValue = Math.max(countSequence(i), maxValue);
        }
        return maxValue;
    }

    public static void main(String args[]) {
        try {
            int i, j;
            while (tokenizeNextLine()) {
                StringBuilder ans = new StringBuilder();
                i = nextInt();
                j = nextInt();
                ans.append(i).append(" ").append(j).append(" ");
                ans.append(maxSequence(Math.min(i, j), Math.max(i, j)));
                println(ans.toString());
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

        try {
            bw.close();
        } catch (IOException e) {}
    }

    public static void print(String output) throws IOException {
        bw.write(output);
        bw.flush();
    }

    public static void print(Object obj) throws IOException {
        print(obj.toString());
    }

    public static void println(String output) throws IOException {
        bw.write(output);
        bw.write('\n');
        bw.flush();
    }

    public static void println(int value) throws IOException {
        println(Integer.toString(value));
    }

    public static void println(long value) throws IOException {
        println(Long.toString(value));
    }

    public static void println(float value) throws IOException {
        println(Float.toString(value));
    }

    public static void println(double value) throws IOException {
        println(Double.toString(value));
    }

    public static void println(Object value) throws IOException {
        println(value.toString());
    }

    public static boolean tokenizeNextLine() {
        try {
            tk = new StringTokenizer(br.readLine());
        } catch (Exception e) {
            return false;
        }
        return tk.hasMoreTokens();
    }

    public static String readLine() throws IOException {
        return br.readLine();
    }

    public static boolean hasNext() {
        return tk.hasMoreTokens();
    }

    public static String next() {
        while (!tk.hasMoreTokens()) {
            try {
                tk = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                System.err.println(e.getMessage());
            }
        }
        return tk.nextToken();
    }

    public static int nextInt() {
        return Integer.parseInt(next());
    }

    public static long nextLong() {
        return Long.parseLong(next());
    }

    public static float nextFloat() {
        return Float.parseFloat(next());
    }

    public static double nextDouble() {
        return Double.parseDouble(next());
    }
}
