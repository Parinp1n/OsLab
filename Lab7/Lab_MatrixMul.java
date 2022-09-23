
import java.util.Arrays;

public class Lab_MatrixMul {
    public static void main(String[] args) {
        int[][] inputA = { { 5, 6, 7 }, { 4, 8, 9 } };
        int[][] inputB = { { 6, 4 }, { 5, 7 }, { 1, 1 } };
        MyData matA = new MyData(inputA);
        MyData matB = new MyData(inputB);
        int matC_r = matA.data.length;
        int matC_c = matB.data[0].length;
        MyData matC = new MyData(matC_r, matC_c);
        Thread[][] t = new Thread[matC_r][matC_c];
        for (int i = 0; i < matC_r; i++) {
            for (int j = 0; j < matC_c; j++) {
                t[i][j] = new Thread(new MatrixMulThread(i, j, matA, matB, matC));
                t[i][j].start();


            }
        }
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[i].length; j++) {
                try {
                    t[i][j].join();
                    } catch (Exception e) {
                    System.out.println(e);
                }
            }
        }
        

        matC.show();
    }
}

class MatrixMulThread implements Runnable {
    int processing_row;
    int processing_col;
    MyData datA;
    MyData datB;
    MyData datC;

    MatrixMulThread(int tRow, int tCol, MyData a, MyData b, MyData c) {
        this.processing_row = tRow;
        this.processing_col = tCol;
        this.datA = a;
        this.datB = b;
        this.datC = c;
    }

    public void run() {
        datC.data[processing_row][processing_col] = 0;
        for (int i = 0; i < datB.data.length; i++) {
            datC.data[processing_row][processing_col] += datA.data[processing_row][i] * datB.data[i][processing_col];
        }
    }
}

// class
class MyData {
    int[][] data;

    MyData(int[][] m) {
        data = m;
    }

    MyData(int r, int c) {
        data = new int[r][c];
        for (int[] aRow : data)
            Arrays.fill(aRow, 9);
        // 9 will be overwritten anyway
    }

    void show() {
        System.out.println(Arrays.deepToString(data));
    }
} // class