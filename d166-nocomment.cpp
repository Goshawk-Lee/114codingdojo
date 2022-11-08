#include <iostream>
using namespace std;
int main ()
{  
  int i,j,m,r;
  int inputcount, empty_count, source_value, tmp_count, location_index;
	m = 51;
	int sourcearray[m], mappingtable[m];
  int targetarray[m]= {};

  /*
    inputcount=9;
    // 題目: 由1開始之連續數字a1.a2.a3...an
    int sourcearray[inputcount] = {1,2,3,4,5,6,7,8,9};
    // 題目: 對有一反轉表：b1.b2...bm。mappingtable[] = { 2 3 6 4 0 2 2 1 0 }
    // 其bm代表意思為：數字m的位置前面有幾個比大個個數。也就是前面保留空格數量
    int mappingtable[inputcount] = {2,3,6,4,0,2,2,1,0};
    // 答案要輪出至 targetarray, 一開始全部為空白值:0, 0代表空白/空格 依反轉表轉出為: { 5 9 1 8 2 6 4 7 3 }
    int targetarray[inputcount] = {0,0,0,0,0,0,0,0,0};
	*/
// 依序輪入 2[Enter]3[Enter]6[Enter]4[Enter]0[Enter]2[Enter]2[Enter]1[Enter]0[Enter]-1[Enter]
// 最後的 -1 表示輪入結束, 下一行輸出結果:  5 9 1 8 2 6 4 7 3
    inputcount=0;
    for (i=0; i< m; i++)
    {
        cin >> r;
		    if (r==-1)
		       break;
		    else
		    {
          mappingtable[i]=r;
          inputcount++;
		    }
    }

    for (i=0; i< inputcount; i++)
        sourcearray[i]=(i+1);


    // 從 由1開始之連續數字a1.a2.a3...an 的 arrary 中, sourcearray[] 從第一個取出, 取到第後的一個 : inputcount
    for (i=0; i< inputcount; i++)
    {
        source_value = sourcearray[i];    // 取出 sourcearray[] 第 i 個位置的值, source_value 記住取出值
        empty_count = mappingtable[i];    // 取出反轉表 mappingtable[] 第 i 個位置的值, empty_count 記住取出值, 就是前面保留空格數量
  
        // 將取出的 source_value, 放入 targetarray[] 的 location_index 位置, 前面保留空格數量為:empty_count
        // 利用用暴力法, 將 targetarray[] 每次都從第一格算起， 空白值個數, 是否符合該保留空格數量:empty_count 的值， 一旦符合即中止迴圈
        tmp_count = 0;
        location_index = 0;
        for (j=0; j< inputcount; j++)
        {
          if (targetarray[j]==0)  // targetarray[j] 數值為0, 識為空格, 有機會塞進較大的值,累計空格數,即為累計幾個比較大的個數
          {
            tmp_count++;  //累計空格數
          }
          if (tmp_count>empty_count)  //累計空格數tmp_count  > 前面該保留空格數量empty_count, 則到了到塞入數值source_value的位置了
          {
            location_index = j;   //累計空格數量到了, 找到 location_index 值: j ,  然後中止 for 迴圈
            break;
          }
        }
        targetarray[location_index] =  source_value;   //將 source_value 放進 targetarray[location_index] 該空格中
    }


    for (i=0; i< inputcount; i++)
    {
        cout << targetarray[i] << " ";
    }
    cout << endl;
   
   return 0;

}