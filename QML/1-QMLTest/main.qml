import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    signal mySig()
    property int bianliang: value
    x:50
    y:50 //相对于父控件
    opacity: 1   //半透明  设置透明度
    minimumHeight: 400  //设置最小宽度
    minimumWidth: 400
    maximumHeight: 600   //设置最大宽度
    maximumWidth: 600

   onWidthChanged:{
        console.log("width=  ",width);
       bianliang++
   }
   onBianliangChanged: {   //变量改变,触发
       console.log("hahahha")
   }

   Button{
       id:btn1
       width:50
       height:50
       focus: true
       objectName: btn1
       background:Rectangle  {
           border.color: btn1.focus ? "red":"black"
       }
        Keys.onLeftPressed: {
            btn2.focus=true

         }
        onActiveFocusChanged: {
            console.log("active fouces item changed",activeFocusItem,"object name",activeFocusItem.objectName)
        }

   }
   Button{
       id:btn2
       width:50
       height:50
       x:50
       objectName: btn2
       background:Rectangle  {
           border.color: btn2.focus ? "red":"black"
       }
       Keys.onRightPressed: {
           btn1.focus=true
       }
       onActiveFocusChanged: {
           console.log("active fouces item changed",activeFocusItem,"object name",activeFocusItem.objectName)
       }

   }
}
