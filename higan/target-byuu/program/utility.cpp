auto Program::pause(bool state) -> void {
  if(paused == state) return;
  paused = state;
  presentation.pauseEmulation.setChecked(paused);

  if(paused) {
    ruby::audio.clear();
    presentation.statusRight.setText("Paused");
  }
}

auto Program::paletteUpdate() -> void {
  if(!emulator) return;
  for(auto& screen : emulator->root->find<higan::Node::Screen>()) {
    screen->setLuminance(settings.video.luminance);
    screen->setSaturation(settings.video.saturation);
    screen->setGamma(settings.video.gamma);
  }
}

auto Program::openFile(BrowserDialog& dialog) -> string {
  if(settings.general.nativeFileDialogs) {
    BrowserWindow window;
    window.setTitle(dialog.title());
    window.setPath(dialog.path());
    window.setFilters(dialog.filters());
    window.setParent(dialog.alignmentWindow());
    return window.open();
  }
  return dialog.openFile();
}
