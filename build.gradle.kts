plugins {
    id("com.android.application") version "8.13.2"
}

repositories {
    google()
    mavenCentral()
}

buildscript {

    // Review these on each update of the AGP (com.android.application)
    gradle.extra["securityPatches"] = listOf(
        "org.apache.httpcomponents:httpmime:4.5.14",
        "org.apache.httpcomponents:httpclient:4.5.14",
        "org.apache.commons:commons-compress:1.27.1",
        "com.google.protobuf:protobuf-java:3.25.5",
        "com.google.protobuf:protobuf-kotlin:3.25.5",
    )

    // Handles the patching of the Android Gradle Plugin
    dependencies {
        constraints {
            for (securityPatch in gradle.extra["securityPatches"] as List<String>) {
                classpath(securityPatch)
            }
        }
    }
}

configurations.named { it.startsWith("_internal-unified-test-platform") }.configureEach {
    // Handles the patching of the Android UTP (Unified Test Platform)
    dependencies {
        constraints {
            for (securityPatch in gradle.extra["securityPatches"] as List<String>) {
                add(name, securityPatch)
            }
        }
    }
}

java {
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(11))
    }
}

android {
    compileSdk = 35
    namespace = "uk.co.baconi.rbg"
    sourceSets.named("main") {
        assets {
            srcDir("${project.rootDir}/assets")
        }
    }
    buildFeatures {
        buildConfig = true
    }
    defaultConfig {
        minSdk = 26
        targetSdk = 35
        versionCode = 5
        versionName = "0.0.5"
        externalNativeBuild {
            cmake {
                arguments += listOf("-DPLATFORM=Android")
                targets += listOf("retro_brick_game")
            }
        }
    }
    externalNativeBuild {
        cmake {
            path = file("CMakeLists.txt")
        }
    }
}
