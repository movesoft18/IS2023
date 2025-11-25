from ultralytics import YOLO

# Load a model
if __name__ == '__main__':
    model = YOLO("yolo11n.pt")  # load a pretrained model (recommended for training)

    # Train the model
    results = model.train(
        data="balloons.yaml",
        epochs=100, 
        imgsz=640,
        single_cls=True,
        device='cpu',
        batch=8,
        cache=True,
        hsv_h = 0.1,
        scale = 0.3,
        flipud = 0.1
        )