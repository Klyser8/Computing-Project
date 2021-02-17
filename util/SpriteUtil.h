#ifndef SFML_TEST_FINAL_SPRITEUTIL_H
#define SFML_TEST_FINAL_SPRITEUTIL_H

inline float calculateScaleFactor(float targetLength, float originalLength) {
    return targetLength / originalLength;
}

inline bool isPointInRect(sf::Vector2f mousePos, float x1, float y1, float x2, float y2) {
    return mousePos.x >= x1 && mousePos.x <= x2 && mousePos.y >= y1 && mousePos.y <= y2;
}

#endif