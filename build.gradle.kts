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
        versionCode = 3
        versionName = "0.0.3"
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
