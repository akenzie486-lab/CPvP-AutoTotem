#include <cstdint>

// Export fungsi registrasi native agar dibaca oleh Levi Mod Loader
extern "C" {
    __attribute__((visibility("default"))) 
    bool PluginInit() {
        // Kode inisialisasi modul ke Levi Launcher
        return true;
    }

    __attribute__((visibility("default"))) 
    void OnClientTick() {
        // Logic AutoTotem
    }
}
