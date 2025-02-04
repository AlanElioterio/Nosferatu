//#include <windows.h>
//#include <gdiplus.h>
//#include <commctrl.h>
//
//
//#define SCREEN_HEIGHT 720
//#define SCREEN_WIDTH 1280
//
//using namespace Gdiplus;
//
//#pragma comment(lib, "gdiplus.lib")
//#pragma comment(lib, "comctl32.lib")
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//void InitializeGDIPlus(GdiplusStartupInput& gdiplusStartupInput, ULONG_PTR& gdiplusToken) {
//    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
//}
//
//void ShutdownGDIPlus(ULONG_PTR& gdiplusToken) {
//    GdiplusShutdown(gdiplusToken);
//}
//
//void DrawLogoAndButton(HDC hdc, HWND hwnd) {
//
//    RECT rect;
//    GetClientRect(hwnd, &rect);

//
//    // Calcular a posição do botão "New Game" abaixo do logo
//    int buttonWidth = 150;
//    int buttonHeight = 40;
//    int buttonX = (SCREEN_WIDTH - buttonWidth) / 2; // Centralizar horizontalmente
//    int buttonY = (SCREEN_HEIGHT / 2) + 100; // Colocar abaixo do logo com um espaço de 20 pixels
//
//    // Criar o botão "New Game" centralizado
//    CreateWindow(
//        "BUTTON",        // Classe do botão
//        "New Game",      // Texto do botão
//        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
//        buttonX, buttonY, buttonWidth, buttonHeight, // Posição e tamanho
//        hwnd, (HMENU)1, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
//}
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
//    // Inicializar o GDI+
//    GdiplusStartupInput gdiplusStartupInput;
//    ULONG_PTR gdiplusToken;
//    InitializeGDIPlus(gdiplusStartupInput, gdiplusToken);
//
//    // Inicializar os controles comuns
//    InitCommonControls();
//
//    // Registrar a classe da janela
//
//    WNDCLASS wc = {0};
//
//    wc.lpfnWndProc = WindowProc;
//    wc.hInstance = hInstance;
//    wc.lpszClassName = "Sample Window Class";
//    RegisterClass(&wc);
//
//    // Criar a janela
//    HWND hwnd = CreateWindowEx(
//        0, "Sample Window Class", "Janela com Logo e New Game", WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT,
//        NULL, NULL, hInstance, NULL);
//
//    if (!hwnd) {
//        return 0;
//    }
//
//    // Exibir a janela
//    ShowWindow(hwnd, nCmdShow);
//    UpdateWindow(hwnd);
//
//    // Chamar a função para desenhar o logo e o botão
//    DrawLogoAndButton(GetDC(hwnd), hwnd);
//
//    // Loop de mensagens
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//
//    // Finalizar o GDI+
//    ShutdownGDIPlus(gdiplusToken);
//
//    return (int) msg.wParam;
//}
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//    case WM_PAINT: {
//        // Manipular a pintura da janela
//        PAINTSTRUCT ps;
//        HDC hdc = BeginPaint(hwnd, &ps);
//        DrawLogoAndButton(hdc, hwnd);  // Desenhar o logo e o botão
//        EndPaint(hwnd, &ps);
//        break;
//    }
//    case WM_COMMAND: {
//        if (LOWORD(wParam) == 1) {
//            // Ação do botão "New Game"
//            MessageBox(hwnd, "Novo Jogo iniciado!", "Jogo", MB_OK);
//        }
//        break;
//    }
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hwnd, uMsg, wParam, lParam);
//    }
//    return 0;
//}
