import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.VirtualKeyboard 2.2


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextField
    {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        onPressed:
        {
            vkb.visible = true
        }
    }

    InputPanel
    {
        id: vkb
        visible: false
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        //这种集成方式下点击隐藏键盘的按钮是没有效果的，
        //只会改变active，因此我们自己处理一下
        onActiveChanged:
        {
            if(!active) { visible = false; }
        }
    }
}
