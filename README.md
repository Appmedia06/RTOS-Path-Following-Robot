# RTOS Path Following Robot
基於RTOS的循跡自走車

# Flow Chart
<img src='https://github.com/Appmedia06/RTOS-Path-Following-Robot/blob/main/img/flow_img.png' width=600/>

# Implement
## RTOS System
* Start task: 將要執行的task以及它的優先級和stack大小丟入startTask(kernel.c)，放入TCB中，接著配置stack並保存CPU暫存器值，最後將此task置READY state  
* Schedule: 設置Timer1以1ms去做schedule，流程即為先保存CPU暫存器值，去做schedule，會比較TCB中所有task的優先級來決定排程，此外也加入"Aging"機制以防同級搶占問題。排程結束後將Stack pointer和CPU暫存器值還原並結束中斷
## Control center
* 為控制循跡功能的中心，架構即為基於Time Sharing的機制，用輪詢的方式檢查按鈕中斷是否發生
## Path Following
* 先將ADC取樣丟入ADC buffer裡，取值時就直接取ADC buffer裡的平均值來分擔誤差。循跡採用閾值法去調整自走車的動作

# Youtube Video
* <a href="https://www.youtube.com/watch?v=CqbXUqrAQH4">RTOS Path Following Robot</a>
