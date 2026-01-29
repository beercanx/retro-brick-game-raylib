plugins {
    id("com.android.application") version "9.0.0"
}

repositories {
    google()
    mavenCentral()
}

buildscript {
    dependencies {
        // Security patching the Android Gradle Plugin in the eyes of the GitHub Dependency Graph.
        constraints {
            classpath("org.apache.httpcomponents:httpmime:4.5.14")
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
