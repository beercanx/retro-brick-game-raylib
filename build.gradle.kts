plugins {
    id("com.android.application") version "8.1.2"
}

repositories {
    mavenLocal()
    mavenCentral()
    google()
}

java {
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(11))
    }
}

android {
    compileSdk = 33
    namespace = "uk.co.baconi.rbg"
    sourceSets.named("main") {
        assets {
            srcDir("${project.rootDir}/assets")
        }
    }
    defaultConfig {
        minSdk = 26
        targetSdk = 33
        versionCode = 4
        versionName = "0.0.4"
        externalNativeBuild {
            cmake {
                arguments += listOf("-DPLATFORM=Android")
                targets += listOf("retro_brick_game")
            }
        }
        ndk {
            abiFilters += listOf("x86", "x86_64", "arm64-v8a") // Excluding 'armeabi-v7a' as raylib 5.0 fails to compile
        }
    }
    externalNativeBuild {
        cmake {
            path = file("CMakeLists.txt")
        }
    }
}
