package ArraySort;
import java.util.Arrays;

public class insertSort implements ArraySort {
    @Override
    public int[] sort(int[] sourceArray) throws Exception {
        int[] arr = Arrays.copyOf(sourceArray, sourceArray.length);
        
        /* Default arr[0] to be sorted, and start comparing from arr[1]. */
        for (int i = 1; i < arr.length; i++) {
            int insertNum = arr[i];
            
            /* 
             * Compare from the right-most of the sorted, and find the first smaller number.
             * If the sorted num is bigger than insertNum, then it should spare the space by noving 
             * to the right neighbouring position; 
             * If the sorted num is smaller than insertNum, then insertNum stays in the crt position.
             */
            int j = i;
            while (j > 0 && insertNum < arr[j - 1]) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = insertNum;
        }
        return arr;
    }
}