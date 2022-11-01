enum class Mode
{
    Slow,
    Fast
};

const float lowerValue = 0.1F;
const float upperValue = 1.0F;
const float speed = 0.002F;
const int cycles = 5;

void setup()
{
    pinMode(10, OUTPUT);
    pinMode(13, OUTPUT);
}

float getPulseValue(const float i)
{
    const float value = (sinf(i * 2.0F * M_PI) + 1.0F) / 2.0F;
    return (lowerValue + value * (upperValue - lowerValue));
}

void writeValue(const float i)
{
    const int value = static_cast<int>(i * 255.0F);
    analogWrite(10, value);
    analogWrite(13, value);
}

void loop()
{
    static float i = 0.0F;
    static Mode mode = Mode::Slow;

    i += speed;

    switch (mode)
    {
        case Mode::Slow:
            writeValue(getPulseValue(i));
            break;
        case Mode::Fast:
            writeValue(getPulseValue(i * 20.0F));
            break;
    }

    delay(10);

    if (i >= static_cast<float>(cycles))
    {
        i = 0.0F;
        mode = (mode == Mode::Slow) ? Mode::Fast : Mode::Slow;
    }
}
