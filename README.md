#  C / Embedded Practice Repository

這是一個用於練習與強化底層系統概念的 C 語言實作倉庫，內容涵蓋資料結構、演算法、以及嵌入式系統基礎開發。  
包含自行實作的 **Stack、Queue、Linked List、Sorting、Binary Search、Bit Operations** 等程式範例。

---

##  專案特點

###  FreeRTOS Wi-Fi Driver / Firmware 模擬
以 FreeRTOS 為基礎，模擬 Wi-Fi Driver 與 Firmware 間的資料流：  
實作 **DMA Ring Buffer、IRQ 同步機制、Bottom-half 任務分工、Firmware Power Save 模擬**。  
重現驅動與韌體的封包傳輸與中斷互動，分析 race condition、互斥鎖與中斷遮罩的設計取捨。

###  資料結構與演算法
手刻 **Stack / Queue / Linked List / Sorting / Searching** 等常用資料結構與演算法，  
強化記憶體操作、指標運算與結構體布局（alignment, padding, endianness）。

###  C 語言底層練習
涵蓋 **指標運算、bitwise 操作、記憶體管理（malloc/free）、critical section、volatile 與中斷旗標（ISR flag）** 等概念。  
聚焦於系統層邏輯與實際執行行為的對應。

---

##  技能涵蓋
`C / C++` · `FreeRTOS` · `Embedded System` · `DMA / Interrupt` · `Data Structure` · `Memory Layout`

---

##  About
此專案作為個人韌體開發與系統程式學習紀錄，專注於**理解軟硬體之間的互動**，  
並透過實作強化對 **作業系統機制（task scheduling / semaphore / critical section）**  
與通訊資料流的整體概念。

---

🛠️ *Made with FreeRTOS and pure C practice.*
