thickness = 0.6;
width = 21;
height = 14;
length = 66;

difference() {
    cube([thickness, width + 2 * thickness, height + 2 * thickness]); // back
    
    translate([-5, 10, 1]) cube([10, 3.4, 2.0]);
}

translate([thickness, 0, 0]) cube([length, width + 2 * thickness, thickness]); // bottom
translate([thickness, 0, height + thickness]) cube([length, width + 2 * thickness, thickness]); // top

translate([thickness, 0, thickness]) cube([length, thickness, height]); // left
translate([thickness, width + thickness, thickness]) cube([length, thickness, height]); // right