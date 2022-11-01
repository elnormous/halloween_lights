thickness = 0.6;
width = 21;
height = 14;
length = 2;

usb_width = 8;
usb_height = 3;

switch_width = 10.6;
switch_height = 5.8;
screw_radius = 1.9 / 2;
screw_distance = 14.6;

$fn = 180;

difference() {
    cube([thickness, width + 2 * thickness, height + 2 * thickness]); // back
    
    translate([-5, width / 2 + thickness - usb_width / 2, 2]) cube([10, usb_width, usb_height]);
    
    translate([-5, width / 2 + thickness - switch_width / 2, 7]) cube([10, switch_width, switch_height]);
    
    translate([-5, width / 2 + thickness - screw_distance / 2, 7 + switch_height / 2])
        rotate([0, 90, 0])
            cylinder(10, screw_radius, screw_radius);

    translate([-5, width / 2 + thickness + screw_distance / 2, 7 + switch_height / 2])
        rotate([0, 90, 0])
            cylinder(10, screw_radius, screw_radius);
}

translate([thickness, thickness, thickness]) cube([length, thickness, height]); // left
translate([thickness, width, thickness]) cube([length, thickness, height]); // right