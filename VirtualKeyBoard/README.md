# VirtualKeyBoard in Qt

1. 在`main.cpp`中，添加`qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));`

記得必須在`QGuiApplication app(argc, argv);` 這行之前

2.  QML中 import `import QtQuick.VirtualKeyboard 2.2`

3. 叫出 InputPanel 

4. 關鍵code

```QML
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
```

