import cv2

# 打印OpenCV版本
print("OpenCV版本:", cv2.__version__)

# 读取并显示图片（需准备一张test.jpg）
img = cv2.imread("test.png")
cv2.imshow("Demo", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
