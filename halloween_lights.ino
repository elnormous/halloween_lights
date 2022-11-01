enum class Mode
{
  Slow,
  Fast
};

const float lowerValue = 0.1F;
const float upperValue = 1.0F;
const int cycles = 5;

void setup()
{
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

float getPulseValue(const float i)
{
  const float value = (sinf(i) + 1.0F) / 2.0F;
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

  i += 0.01F;

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

  if (i >= static_cast<float>(cycles) * 2.0F * M_PI)
  {
    i = 0.0F;
    mode = (mode == Mode::Slow) ? Mode::Fast : Mode::Slow;
  }
}
