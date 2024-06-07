package ArraySort;
import java.util.Arrays;

public class mergeSort implements ArraySort {
    @Override
    public int[] sort(int[] sourceArray) throws Exception {
        int[] arr = Arrays.copyOf(sourceArray, sourceArray.length);
        int[] tmpArr = new int[arr.length];
        /* For algorithms involving recursion, typically we explicitly define a private helper. */
        mergeSort(arr, tmpArr, 0, arr.length - 1);
        return arr;
    }

    private static void mergeSort(int[] arr, int[] tmpArr, int left, int right) {
        if (left < right) {
            int center = (left + right) / 2;
            mergeSort(arr, tmpArr, left, center);
            mergeSort(arr, tmpArr, center + 1, right);
            merge(arr, tmpArr, left, center + 1, right);
        }
    }

    private static void merge(int[] arr, int[] tmpArr, int leftPos, int rightPos, int rightEnd) {
        int tmpPos = leftPos;
        int leftEnd = rightPos - 1;
        int numOfElements = rightEnd - leftPos + 1;
        
        /* Elements of both sub-arrays are not completely assigned. */
        while (leftPos <= leftEnd && rightPos <= rightEnd) {
            if (arr[leftPos] <= arr[rightPos])
                tmpArr[tmpPos++] = arr[leftPos++];
            else
                tmpArr[tmpPos++] = arr[rightPos++];
        }

        /* Assign the rest elements into the array, and only one of the loops would be executed. */
        while (leftPos <= leftEnd)
            tmpArr[tmpPos++] = arr[leftPos++];
        while (rightPos <= rightEnd)
            tmpArr[tmpPos++] = arr[rightPos++];
        
        arr = Arrays.copyOf(tmpArr, tmpArr.length);
        }
    }

