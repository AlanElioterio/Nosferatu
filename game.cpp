//#include <windows.h>
//
//
//#define SPRITE_WIDTH  160
//#define SPRITE_HEIGHT 20
//#define SPRITE_COUNT  8
//
//// Window dimensions
//const int WIDTH = 1280;
//const int HEIGHT = 720;
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//void LoadSprite();
//void DrawSprite(HDC hdc);
//void DrawSpriteTransparent(HDC hdc, int x, int y, int spriteIndex);
//
//HBITMAP hSprite;
//                // left, top, right, bottom
//RECT spriteRect = {100, 480, 140, 540};
//
//// Block properties
//            // left, top, right, bottom
//RECT ground = {0 , 540, WIDTH, WIDTH};
//
//int velocityY = 0;
//bool isJumping = false;
//
//// Game loop variables
//bool running = true;
//
//int currentSpriteIndex = 0;
//
//
//int spriteChangeCounter = 0;
//
//// Window procedure
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
////    switch (uMsg) {
////        case WM_DESTROY:
////            PostQuitMessage(0);
////            running = false;
////            return 0;
////
////        case WM_KEYDOWN:
////            if (wParam == VK_SPACE && !isJumping) {
////                velocityY = -15; // Jump strength
////                isJumping = true;
////            }
////            return 0;
////        default: ;
////    }
////    return DefWindowProc(hwnd, uMsg, wParam, lParam);
//
//    switch (uMsg)
//    {
//
//        case WM_KEYDOWN:
//            if ((wParam == VK_SPACE || wParam == VK_UP) && !isJumping) {
//                velocityY = -15; // Jump strength
//                isJumping = true;
//            }
//            return 0;
//        break;
//        case WM_DESTROY:
//            PostQuitMessage(0);
//            running = false;
//            break;
//        default:
//            return DefWindowProc(hwnd, uMsg, wParam, lParam);
//    }
//    return 0;
//}
//
//// Entry point
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
//    WNDCLASS wc = {0};
//    wc.lpfnWndProc = WindowProc;
//    wc.hInstance = hInstance;
//    wc.lpszClassName = "BlockJumpGame";
//    RegisterClass(&wc);
//
//    HWND hwnd = CreateWindowEx(0, "BlockJumpGame", "Nosferatu", WS_OVERLAPPEDWINDOW,
//                               CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEIGHT,
//                               NULL, NULL, hInstance, NULL);
//    ShowWindow(hwnd, nCmdShow);
//    LoadSprite();
//
//    HDC hdc;
//    MSG msg;
//
//    while (running) {
//        // Handle messages
//        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//
//
//        // Update physics
//        spriteRect.left += 5; // Move forward
//        spriteRect.right += 5;
//
//        if (spriteRect.left > WIDTH) { // Loop back
//            spriteRect.left = -40;
//            spriteRect.right = 0;
//        }
////
//        if (isJumping) {
//            spriteRect.top += velocityY;
//            spriteRect.bottom += velocityY;
//            velocityY += 1; // Gravity
//            currentSpriteIndex = 3;
//
//            if (spriteRect.bottom >= 540) { // Ground collision
//                spriteRect.bottom = 540;
//                spriteRect.top = 480;
//                isJumping = false;
//            }
//        }
//        else{
//            spriteChangeCounter++;
//
//            if (spriteChangeCounter % 5 == 0) {
//                if (currentSpriteIndex == 3){
//                    currentSpriteIndex = 2;
//                }
//                else{
//                    currentSpriteIndex = 3;
//                }
//
//            }
//        }
//
//        // Rendering
//        hdc = GetDC(hwnd);
//
//        RECT background = {0, 0, WIDTH, HEIGHT}; // Define a persistent RECT
//        FillRect(hdc, &background, (HBRUSH)(COLOR_WINDOW + 1)); // Clear screen
//
//        HBRUSH hBrush = CreateSolidBrush(RGB(72, 50, 168));
//        FillRect(hdc, &ground, (HBRUSH)GetStockObject(BLACK_BRUSH)); // Draw block
////
//        PAINTSTRUCT ps;
//        DrawSpriteTransparent(hdc, spriteRect.left, spriteRect.top, currentSpriteIndex);
//        EndPaint(hwnd, &ps);
//
//        ReleaseDC(hwnd, hdc);
//
//        Sleep(13);  // ~60 FPS
//    }
//
//    return 0;
//}
//
//
//void LoadSprite()
//{
//    hSprite = (HBITMAP)LoadImage(NULL, "nosferatu.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
//}
//void DrawSpriteTransparent(HDC hdc, int x, int y, int spriteIndex)
//{
//    if (hSprite)
//    {
//        HDC hdcMem = CreateCompatibleDC(hdc);
//        HGDIOBJ oldBitmap = SelectObject(hdcMem, hSprite);
//
//        int srcX = (spriteIndex * 20);
//
//        TransparentBlt(hdc, x, y, 60, 60, hdcMem, srcX, 0, 20, 20, RGB(255, 0, 255));
//
//        SelectObject(hdcMem, oldBitmap);
//        DeleteDC(hdcMem);
//    }
//}
