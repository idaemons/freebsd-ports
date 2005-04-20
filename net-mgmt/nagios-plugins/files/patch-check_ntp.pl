--- plugins-scripts/check_ntp.pl.orig	Fri Nov 19 04:59:43 2004
+++ plugins-scripts/check_ntp.pl	Fri Dec  3 23:54:19 2004
@@ -274,7 +274,7 @@
 			}
 			
 			# match sys.peer or pps.peer
-			if (/^(\*|o)([-0-9.\s]+)\s+([-0-9A-Za-z.]+)\s+([-0-9.]+)\s+([lumb-]+)\s+([-0-9m.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)/) {
+			if (/^(\*|o)([-0-9.\s]+)\s+([-0-9A-Za-z.]+)\s+([-0-9.]+)\s+([lumb-]+)\s+([-0-9m.]+)\s+([-0-9m.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)/) {
 				$syspeer = $2;
 				$stratum = $4;
 				$jitter = $11;
@@ -299,7 +299,7 @@
 		unless (defined $syspeer) {
 			if ($#candidates >0) {
 				foreach my $c (@candidates) {
-					$c =~ /^(#)([-0-9.\s]+)\s+([-0-9A-Za-z.]+)\s+([-0-9.]+)\s+([lumb-]+)\s+([-0-9m.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)/;
+					$c =~ /^(#)([-0-9.\s]+)\s+([-0-9A-Za-z.]+)\s+([-0-9.]+)\s+([lumb-]+)\s+([-0-9m.]+)\s+([-0-9m.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)/;
 					$syspeer = $2;
 					$stratum = $4;
 					$jitter = $11;
