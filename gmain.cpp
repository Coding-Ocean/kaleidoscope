#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    VECTOR3 pre, mou, pre_,mou_;
    MATRIX matrix;
    float cx = width / 2;
    float cy = height / 2;
    float deg = 0;
    int n = 24;
    float angle = 360.0f / n;
    angleMode(DEGREES);
    colorMode(HSV);
    float clearColor = 0;
    clear(clearColor);
    while (notQuit) {
        if (isTrigger(MOUSE_RBUTTON)) {
            clear(clearColor);
        }
        if (isPress(MOUSE_LBUTTON)) {
            mou.x = mouseX;
            mou.y = mouseY;
            float dist = length(pre - mou);
            float sw = map(dist, 0, 500, 0.8f, 6);
            strokeWeight(sw);
            stroke(deg, 255, 255);
            deg += 10;
            for (int i = 0; i < n; i++) {
                matrix.identity();
                matrix.mulTranslate(cx, cy);
                matrix.mulRotateZ(angle * i);
                matrix.mulTranslate(-cx, -cy);
                pre_ = matrix * pre;
                mou_ = matrix * mou;
                line(pre_.x, pre_.y, mou_.x, mou_.y);
                matrix.identity();
                matrix.mulTranslate(cx, cy);
                matrix.mulRotateZ(angle * i);
                matrix.mulScale(1, -1);
                matrix.mulTranslate(-cx, -cy);
                pre_ = matrix * pre;
                mou_ = matrix * mou;
                line(pre_.x, pre_.y, mou_.x, mou_.y);
            }
            pre = mou;
        }
        else {
            pre.x = mouseX;
            pre.y = mouseY;
        }
    }
}