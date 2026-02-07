import cv2
import numpy as np
import multiprocessing

class SharedFrameHeader:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.size = width * height * 3 // 2  # NV12 format: Y + UV

    @property
    def frame_shape(self):
        return (self.height, self.width, 3)

def capture_to_shared_memory(shared_memory_name, width=1280, height=720):
    # Create shared memory
    shared_memory = multiprocessing.Array('B', width * height * 3 // 2)
    header = SharedFrameHeader(width, height)

    # Open OBS Virtual Camera
    cap = cv2.VideoCapture('video=OBS Virtual Camera')
    
    if not cap.isOpened():
        print('Error: Could not open OBS Virtual Camera')
        return

    while True:
        ret, frame = cap.read()
        if not ret:
            print('Error: Failed to capture frame')
            break

        # Convert the frame to NV12 format
        nv12_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2YUV_I420)
        nv12_frame = nv12_frame.reshape((height * 3 // 2, width))  # Reshape for NV12

        # Write frame to shared memory
        shared_memory[:] = nv12_frame.flatten()[:]

        # Introduce micro-jitter
        cv2.waitKey(30)

    cap.release()

if __name__ == '__main__':
    capture_to_shared_memory('shared_feeder', 1280, 720)