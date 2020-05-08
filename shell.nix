{ pkgs ? import ./nix {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    arduino-core
    jre
  ];

  ARDUINO_BOARD = "arduino:avr:uno";
  ARDUINO_PORT  = "/dev/ttyACM0";

  shellHook = ''
    alias upload='arduino --board "$ARDUINO_BOARD" --port "$ARDUINO_PORT" --upload "$ARDUINO_MAIN"'
    export PATH="$PATH:${pkgs.arduino-core}/share/arduino"
  '';
}
