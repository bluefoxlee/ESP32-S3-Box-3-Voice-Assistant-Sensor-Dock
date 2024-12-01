#include <string>

bool is_utf8_start_byte(char c) {
    // 检查是否是UTF-8字符的起始字节
    return (c & 0xC0) != 0x80;
}

void print_wrapped_text(esphome::display::Display &it, int x, int y, esphome::display::BaseFont *font, esphome::Color color, const char *text, int max_width) {
    int cursor_x = x;
    int cursor_y = y;
    std::string utf8_text = text;

    // 行高：根据字体调整合适的值
    int line_height = 15; // 假设每行高度为15像素

    size_t start = 0;
    size_t current = 0;
    std::string line;

    while (current < utf8_text.length()) {
        // 获取下一个UTF-8字符
        size_t char_start = current;
        do {
            current++;
        } while (current < utf8_text.length() && !is_utf8_start_byte(utf8_text[current]));

        std::string char_str = utf8_text.substr(char_start, current - char_start);
        line += char_str;

        int x1, y1, width, height;
        it.get_text_bounds(cursor_x, cursor_y, line.c_str(), font, esphome::display::TextAlign::TOP_LEFT, &x1, &y1, &width, &height);

        if (width > max_width || char_str == "\n") {
            // 如果当前行超出最大宽度，或者遇到换行符

            // 移除最后一个字符
            line.erase(line.size() - char_str.size(), char_str.size());

            // 打印当前行
            it.print(cursor_x, cursor_y, font, color, line.c_str());

            // 移动到下一行
            cursor_y += line_height;

            // 重置当前行
            line = char_str == "\n" ? "" : char_str;
        }
    }

    // 打印剩余的文本
    if (!line.empty()) {
        it.print(cursor_x, cursor_y, font, color, line.c_str());
    }
}