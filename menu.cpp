#define IDI_MYICON 101
#include <windows.h>
#include <gdiplus.h>

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280

using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void InitializeGDIPlus(GdiplusStartupInput& gdiplusStartupInput, ULONG_PTR& gdiplusToken) {
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

void ShutdownGDIPlus(ULONG_PTR& gdiplusToken) {
    GdiplusShutdown(gdiplusToken);
}

// Menu options
const wchar_t* menuItems[] = { L"New Game", L"Options", L"Exit" };
const int menuCount = 3;
int selectedIndex = 0; // Currently selected option

void DrawMenu(HDC hdc, HWND hwnd) {


    RECT rect;
    GetClientRect(hwnd, &rect);

    HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0)); // Cor preta
    FillRect(hdc, &rect, blackBrush);
    DeleteObject(blackBrush);  // Limpar o pincel

    // Caminho para o logo
    WCHAR path[] = L"nosferatu_logo_c.png"; // Coloque o caminho para o seu logo
    Image logo(path);

    // Criar o objeto Graphics
    Graphics graphics(hdc);

    Image image(L"main_nosferatu_game.png");
    graphics.DrawImage(&image, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Desenhar o logo no topo da janela
    int logoWidth = 360;
    int logoHeight = 200;
    int logoX = ((SCREEN_WIDTH - logoWidth) / 2); // Centralizar horizontalmente
    int logoY = (SCREEN_HEIGHT / 2) - 200; // Posição fixa do topo

    graphics.DrawImage(&logo, logoX, logoY, logoWidth, logoHeight);

    SolidBrush brush(Color(255, 255, 255)); // White text
    SolidBrush selectedBrush(Color(138, 137, 136)); // Yellow for selected item

    PrivateFontCollection fontCollection;
    fontCollection.AddFontFile(L"pixel_arial.ttf");

    // Get the first font family in the collection
    int numFound = 0;
    int numFamilies = fontCollection.GetFamilyCount();
    FontFamily fontFamily;
    fontCollection.GetFamilies(1, &fontFamily, &numFound);
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);

    StringFormat format;
    format.SetAlignment(StringAlignmentCenter);
    format.SetLineAlignment(StringAlignmentCenter);

    int startY = 400; // Start drawing menu at this Y position

    for (int i = 0; i < menuCount; i++) {
        PointF point((SCREEN_WIDTH / 2), startY + (i * 50));
        if (i == selectedIndex) {
            graphics.DrawString(menuItems[i], -1, &font, point, &format, &selectedBrush);
        } else {
            graphics.DrawString(menuItems[i], -1, &font, point, &format, &brush);
        }
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    InitializeGDIPlus(gdiplusStartupInput, gdiplusToken);

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "NosferatuMenu";
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON)); // Load custom icon
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, "NosferatuMenu", "Nosferatu", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, NULL, hInstance, NULL);

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ShutdownGDIPlus(gdiplusToken);
    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        DrawMenu(hdc, hwnd);
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_KEYDOWN: {
        switch (wParam) {
        case VK_UP:
            if (selectedIndex > 0) selectedIndex--;
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        case VK_DOWN:
            if (selectedIndex < menuCount - 1) selectedIndex++;
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        case VK_RETURN: // Pressing ENTER
            if (selectedIndex == 0) MessageBox(hwnd, "Starting New Game!", "Game", MB_OK);
            else if (selectedIndex == 1) MessageBox(hwnd, "Options selected!", "Game", MB_OK);
            else if (selectedIndex == 2) PostQuitMessage(0); // Exit game
            break;
        }
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
