import java.util.ArrayList;
import java.util.Arrays;

public class Sort {
    /**
     * 冒泡排序
     */
    public static int [] bubbleSort(int [] array){
        if (array.length==0){
            System.out.println("数组不能为空");
//            return array;
        }
        for (int i=0;i<array.length;i++){
                for (int j=0;j<array.length-1-i;j++){
                    if (array[j+1]< array[j]){
                        int temp=array[j+1];
                        array[j+1]=array[j];
                        array[j]=temp;

                    }
                }

        }
        return array;
    }

    /**
     * 选择排序
     * @param array
     */
    public static int [] slectionSort(int [] array){
        if (array.length==0){
            System.out.println("数组不能为空");
//            return array;
        }
        for (int i=0;i<array.length;i++){
            int minIndex=i;
            for (int j=i;j<array.length;j++){
                if (array[j]<array[minIndex]){
                    minIndex=j;
                }

            }
            int temp=array[minIndex];
            array[minIndex]=array[i];
            array[i]=temp;

        }
        return array;
    }

    /**
     * 插入排序
     * @param
     */
    public static int [] insertionSort(int [] array){
        if (array.length==0){
            System.out.println("数组不能为空");
//            return array;
        }
        int current;//当前的下标
        for (int i=0;i<array.length-1;i++){
            current=array[i+1];
            int preIndex=i;
            while (preIndex>=0&&current<array[preIndex]){
                array[preIndex+1]=array[preIndex];
                preIndex--;
            }
            array[preIndex+1]=current;
        }
        return array;
    }

    /**
     * 希尔排序
     * @param array
     */
    public static int [] ShellSort(int [] array){
        int len=array.length;
        int temp,gap=len/2;
        while (gap>0){
            for (int i=gap;i<len;i++){
                temp=array[i];
                int preIndex=i-gap;
                while (preIndex >=0 &&array[preIndex]>temp){
                    array[preIndex+gap]=array[preIndex];
                    preIndex-=gap;
                }
                array[preIndex+gap]=temp;
            }
            gap /=2;
        }
        return array;
    }

    /**
     * 归并排序
     * @param array
     */
    public static int [] MergeSort(int [] array){
//        int len=array.length;
        if (array.length<2){return array;}
        int mid=array.length/2;
        int [] left= Arrays.copyOfRange(array,0,mid);
        int [] right=Arrays.copyOfRange(array,mid,array.length);
        return merge(MergeSort(left),MergeSort(right));
    }
    /**
     *
     * @param left
     * @param right
     * @return
     */
    public static int[] merge(int[] left, int[] right) {
        int [] result=new int[left.length+right.length];
        for (int index=0,i=0,j=0;index<result.length;index++){
            if (i>=left.length){
                result[index]=right[j++];
            }
            else if (j>=right.length){
                result[index]=left[i++];
            }
            else if (left[i]>right[j]){
                result[index]=right[j++];
            }else{
                result[index]=left[i++];
            }

        }
        return result;
    }


    /**
     * 归并排序
     */

    public static int[] mergeSort(int[] nums, int l, int h) {
        if (l == h)
            return new int[] { nums[l] };

        int mid = l + (h - l) / 2;
        int[] leftArr = mergeSort(nums, l, mid); //左有序数组
        int[] rightArr = mergeSort(nums, mid + 1, h); //右有序数组
        int[] newNum = new int[leftArr.length + rightArr.length]; //新有序数组

        int m = 0, i = 0, j = 0;
        while (i < leftArr.length && j < rightArr.length) {
            newNum[m++] = leftArr[i] < rightArr[j] ? leftArr[i++] : rightArr[j++];
        }
        while (i < leftArr.length)
            newNum[m++] = leftArr[i++];
        while (j < rightArr.length)
            newNum[m++] = rightArr[j++];
        return newNum;
    }

    /**
     * 快速排序
     * 基准(pivot)
     * @param array
     */
    public static int [] QuickSort(int [] array,int start,int end){
        if (array.length<1 || start<0 || end>=array.length || start>end){return null;}

        int smallIndex=partition(array,start,end);
        if (smallIndex>start){
            QuickSort(array,start,smallIndex-1);
        }
        if (smallIndex<end){
            QuickSort(array,smallIndex-1,end);
        }
        return array;
    }

    private static int partition(int[] array, int start, int end) {
        int privot= (int) (start+Math.random()*(end-start+1));

        int smallIndex=start-1;
        swap(array,privot,end);
        for (int i=start;i<=end;i++){
            if (array[i]<=array[end]){
                smallIndex++;
                if (i>smallIndex){
                    swap(array,i,smallIndex);
                }
            }
        }
        return smallIndex;
    }

    private static void swap(int[] array, int i, int smallIndex) {
        int temp=array[i];
        array[i]=array[smallIndex];
        array[smallIndex]=temp;
    }


    /**
     * 堆排序
     * @param args
     */
    static int len;
    public static int [] HeapSort(int [] array){
        len=array.length;
        if (len<1){return array;}
        //构建最的堆
        buildMaxHeap(array);
        while (len>0){
            swap(array,0,len-1);
            len--;
            adjustHeap(array,0);
        }
        return array;
    }

    /**
     * 建立最大堆
     *
     * @param array
     */
    private static void buildMaxHeap(int[] array) {
        //从最后一个非叶子节点开始向上构造最大堆
        for (int i = (len/2+1);i>=0;i-- ){
            adjustHeap(array,i);
        }
    }

    /**
     *调整使之成为最大堆
     *
     * @param array
     * @param i
     */

    private static void adjustHeap(int[] array, int i) {
        int maxIndex=i;
        //如果有左树,且左子树大于父节点,则将最大指针指向左子树
        if (i*2<len && array[i*2] >array[maxIndex]){
            maxIndex=i*2;
        }
        //如果有右树,且右子树大于父节点,则将最大指针指向右子树
        if ((i*2+1)<len && array[i*2+1]>array[maxIndex]){
            maxIndex=i*2+1;
        }
        //如果父节点不是最大值,则将父接节点与最大值交换,并且递归调整与父节点交换位置
        if (maxIndex!=i){
            swap(array,maxIndex,i);
            adjustHeap(array,maxIndex);
        }
    }


    /**
     * 计数排序
     *
     * @param array
     */
    public static int [] CountingSort(int [] array){
        if (array.length==0){return array;}

        int bias,min=array[0],max=array[0];

        for (int i=1;i<array.length;i++){
            if (array[i]>max){
                max=array[i];
            }
            if (array[i]<min){
                min=array[i];
            }
        }
        bias=0-min;

        int [] bucket=new int[max - min +1];

        Arrays.fill(bucket,0);

        for (int i=0;i<array.length;i++){
            bucket[array[i]+bias]++;
        }

        int index=0,i=0;

        while (index<array.length){
            if (bucket[i] !=0){
                array[index]=i-bias;
                bucket[i]--;
                index++;
            }else{
                i++;
            }
        }
        return array;
    }

    /**
     * 桶排序
     *
     * @param array
     */
    public static ArrayList<Integer> BucketSort(ArrayList<Integer> array,int bucketSize){
        if (array==null || array.size()<0){return array;}

        int max=array.get(0),min=array.get(0);
        //找到最大值最小值

        for (int i=0;i<array.size();i++){
            if (array.get(i)>max){
                max=array.get(i);
            }
            if (array.get(i)<min){
                min=array.get(i);
            }
        }

        int bucketCount=(max-min)/bucketSize+1;

        ArrayList<ArrayList<Integer>> bucketArr=new ArrayList<>(bucketCount);

        ArrayList<Integer> resultArr=new ArrayList<>();

        for (int i=0;i<bucketCount;i++){
           bucketArr.add(new ArrayList<Integer>());
        }
        for ( int i =0; i<array.size();i++){
            bucketArr.get((array.get(i)-min)/bucketSize).add(array.get(i));
        }
        for (int i=0;i<bucketCount;i++){
            if (bucketSize==1){
                for (int j=0;j<bucketArr.get(i).size();j++){
                    resultArr.add(bucketArr.get(i).get(j));
                }
            }else{
                if (bucketCount==1){
                    bucketSize--;
                    ArrayList<Integer> temp=BucketSort(bucketArr.get(i),bucketSize);
                    for (int j=0;j<temp.size();j++){
                        resultArr.add(temp.get(j));
                    }
                }
            }
        }
        return resultArr;
    }

    /**
     * 基数排序
     *
     * @param array
     */

    public static int [] RadixSort(int [] array){
        if (array==null || array.length<2){return null;}
        //先算出最大的位数

        int max=array[0];
        for (int i= 1;i<array.length;i++){
            max=Math.max(max,array[i]);
        }
        int maxDight=0;
        while (max!=0){
            max/=10;
            maxDight++;
        }

        int mod=10,div=1;
        ArrayList<ArrayList<Integer>> bucketList=new ArrayList<ArrayList<Integer>>();
        for (int i=0;i<10;i++){
            bucketList.add(new ArrayList<Integer>());
        }
        for (int i=0;i<maxDight;i++,mod*=10,div*=10){
            for (int j=0;j<array.length;j++){
                int num=(array[j]%mod)/div;
                bucketList.get(num).add(array[j]);
            }
        }
        int index=0;
        for (int j=0;j<bucketList.size();j++){
            for (int k=0;k<bucketList.get(j).size();k++){
                array[index++]=bucketList.get(j).get(k);
                bucketList.get(j).clear();
            }
        }
        return array;
    }
    public static void main(String[] args) {
        int[] array={9,1,3,4,14,5,10,24,18};
        ArrayList<Integer> arrayList=new ArrayList<>();
////        bubbleSort(array);
////        slectionSort(array);
////        insertionSort(array);
////        ShellSort(array);
//          int[] newNums = mergeSort(array, 0, array.length - 1);
//        int[] newNums=MergeSort(array);
//        int [] newNums =QuickSort(array,0,8);
//          int [] newNums =HeapSort(array);
//            int [] newNums =CountingSort(array);
//            int [] newNums =CountingSort(array);
            int [] newNums =RadixSort(array);
        for (int arr: newNums) {
            System.out.println(arr);
        }
    }
}
