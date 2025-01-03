#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_INVENTORY 100 // 最多有100筆存貨資料
#define MAX_ERRORS 100    // 最多有100筆錯誤資料

typedef char Str30[30]; // 能存放最多30個字元的字串


typedef struct Product {
    Str30 barCode;         // 條碼（有時稱「序號」）
    Str30 name;            // 商品名稱
    int cost;              // 成本
    int amountLeft;        // 倉庫中有多少貨
    int amountSold;        // 總共賣出幾件
    int bestProfitPerItem; // 單筆最佳利潤（注意！這是正數）
    int worstLossPerItem;  // 單筆最慘損失（注意！這是負數）
    int profit;            // 總共賺了多少
} Product;

int gNumOfProducts = 0; // 'inventory[]'之中總共有多少筆存貨資料

typedef enum ErrorType {
    BAR_CODE_FORMAT_ERROR = 1829371,  // 條碼格式錯誤
    BAR_CODE_WRONG = 2172429,         // 條碼錯誤（商品名稱有問題）
    NO_SUCH_PRODUCT = 3282617,        // 商品不存在
    NEGATIVE_NUMBER = 4791202,        // 負數錯誤
    NOT_ENOUGH_CAPITAL = 5012743,     // 資本不足
    NOT_ENOUGH_MERCHANDISE = 6139072, // 商品不足
    DATE_FORMAT_ERROR = 7791023,      // 日期格式錯誤
    DATE_CONTENT_ERROR = 8221719,     // 日期內容錯誤
    DATE_SEQUENCE_ERROR = 9237291     // 日期順序錯誤
} ErrorType;

typedef struct Error {
    ErrorType type; // 是什麼形式的錯誤
    Str30 barCode;  // 條碼（如果需要記下就記在這裡）
    Str30 name;     // 商品名稱（如果需要記下就記在這裡）
    Str30 dateStr;  // 日期的字串（如果需要記下就記在這裡）
} Error;


int gNumOfErrors = 0; // 'errors[]'之中總共有多少筆錯誤資料

typedef struct Date {
    int year;
    int month;
    int day;
} Date; // struct Date

Date gCurrentDate = {0, 0, 0}; // 目前的日期

typedef struct Statistics {
    int capital;                      // 目前本店手頭上有多少資本
    int salesOfCurrentDate;           // 到目前一天的銷售額
    int netSales;                     // 到目前為止全部的銷售額
    int netProfit;                    // 到目前為止全部（因為銷售貨品）賺到的錢
    int bestSalesYear, bestSalesMonth, bestSalesDay;   // 銷售額最高的是哪一年、哪個月、哪一天
    int bestSalesAmount;              // 銷售額最高的是多少
    int worstSalesYear, worstSalesMonth, worstSalesDay; // 銷售額最低的是哪一年、哪個月、哪一天
    int worstSalesAmount;             // 銷售額最低的是多少
} Statistics;

//Statistics gStat = {0, 0, 0, 0, 0, 0, 0, INT_MIN, 0, 0, 0, INT_MAX};

typedef struct PurchasedItem {
    Str30 barCode;  // 條碼（有時稱「序號」）
    Str30 name;     // 商品名稱
    int unitPrice;  // 單價
    int amount;     // 買的個數
} PurchasedItem; // struct PurchasedItem

typedef struct SoldItem {
    Str30 barCode;  // 條碼（有時稱「序號」）
    Str30 name;     // 商品名稱
    int unitPrice;  // 單價
    int amount;     // 賣出的個數
} SoldItem; // struct SoldItem

void Stock(Product inventory[MAX_INVENTORY]) {
    scanf("%d", &gNumOfProducts);

    for (int i = 0; i < gNumOfProducts; i++) {
       
        scanf("%s", inventory[i].barCode);	// 輸入條碼 
        scanf("%s", inventory[i].name);		// 輸入商品名稱 
        scanf("%d", &inventory[i].cost);	// 輸入成本 
        scanf("%d", &inventory[i].amountLeft);		// 輸入初始庫存量 

        inventory[i].amountSold = 0;		// 	設定已售出量的初始檔 
        inventory[i].profit = 0;		//  設定利潤的初始量 
        inventory[i].bestProfitPerItem = 2147483647		// INT_MAX 變數類型為int的最大初始值	
        inventory[i].worstLossPerItem = -2147483647 - 1		// INT_MIN 變數類型為int的最小初始值
    }
} 

int main(){
  printf("YOU ARE GAY!");

  printf("PIYAN");

  return 0;
}
