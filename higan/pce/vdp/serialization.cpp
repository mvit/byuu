auto VDP::serialize(serializer& s) -> void {
  Thread::serialize(s);

  vce.serialize(s);
  vdc0.serialize(s); if(Model::SuperGrafx())
  vdc1.serialize(s); if(Model::SuperGrafx())
  vpc.serialize(s);

  s.integer(io.hcounter);
  s.integer(io.vcounter);
}

auto VCE::serialize(serializer& s) -> void {
  s.array(cram.memory);
  s.integer(cram.address);

  s.integer(io.clock);
  s.integer(io.extraLine);
  s.integer(io.grayscale);
}

auto VDC::serialize(serializer& s) -> void {
  s.integer(output);

  s.array(vram.memory);
  s.integer(vram.addressRead);
  s.integer(vram.addressWrite);
  s.integer(vram.addressIncrement);
  s.integer(vram.dataRead);
  s.integer(vram.dataWrite);

  s.array(satb.memory);

  s.integer(irq.line);
  s.integer(irq.collision.enable);
  s.integer(irq.collision.pending);
  s.integer(irq.overflow.enable);
  s.integer(irq.overflow.pending);
  s.integer(irq.coincidence.enable);
  s.integer(irq.coincidence.pending);
  s.integer(irq.vblank.enable);
  s.integer(irq.vblank.pending);
  s.integer(irq.transferVRAM.enable);
  s.integer(irq.transferVRAM.pending);
  s.integer(irq.transferSATB.enable);
  s.integer(irq.transferSATB.pending);

  s.integer(dma.sourceIncrementMode);
  s.integer(dma.targetIncrementMode);
  s.integer(dma.satbRepeat);
  s.integer(dma.source);
  s.integer(dma.target);
  s.integer(dma.length);
  s.integer(dma.satbSource);
  s.integer(dma.vramActive);
  s.integer(dma.satbActive);
  s.integer(dma.satbPending);
  s.integer(dma.satbOffset);

  s.integer(timing.horizontalSyncWidth);
  s.integer(timing.horizontalDisplayStart);
  s.integer(timing.horizontalDisplayLength);
  s.integer(timing.horizontalDisplayEnd);
  s.integer(timing.verticalSyncWidth);
  s.integer(timing.verticalDisplayStart);
  s.integer(timing.verticalDisplayLength);
  s.integer(timing.verticalDisplayEnd);
  s.integer(timing.hoffset);
  s.integer(timing.voffset);
  s.integer(timing.hstart);
  s.integer(timing.vstart);
  s.integer(timing.hlength);
  s.integer(timing.vlength);

  s.integer(io.address);
  s.integer(io.externalSync);
  s.integer(io.displayOutput);
  s.integer(io.dramRefresh);
  s.integer(io.coincidence);
  s.integer(io.vramAccess);
  s.integer(io.spriteAccess);
  s.integer(io.cgMode);

  s.integer(background.enable);
  s.integer(background.hscroll);
  s.integer(background.vscroll);
  s.integer(background.vcounter);
  s.integer(background.width);
  s.integer(background.height);
  s.integer(background.hoffset);
  s.integer(background.voffset);
  s.integer(background.color);
  s.integer(background.palette);

  //todo: serialize array<sprite.objects>
  s.integer(sprite.enable);
  s.integer(sprite.color);
  s.integer(sprite.palette);
  s.integer(sprite.priority);
}

auto VDC::Object::serialize(serializer& s) -> void {
  s.integer(y);
  s.integer(x);
  s.integer(mode);
  s.integer(pattern);
  s.integer(palette);
  s.integer(priority);
  s.integer(width);
  s.integer(height);
  s.integer(hflip);
  s.integer(vflip);
  s.integer(first);
}

auto VPC::serialize(serializer& s) -> void {
  for(auto& setting : settings) {
    s.integer(setting.enableVDC0);
    s.integer(setting.enableVDC1);
    s.integer(setting.priority);
  }
  s.array(window);
  s.integer(select);
}
